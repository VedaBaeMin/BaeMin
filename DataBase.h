#ifndef BAEMIN_DATABASE_H
#define BAEMIN_DATABASE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>

// 데이터 요소와 그 요소의 mutex를 함께 묶은 구조체
template <typename T>
class Element {
public:
    std::shared_ptr<T> data;
    mutable std::mutex mtx;  // 각 요소마다 독립적인 mutex

    // 기본 생성자
    Element() = default;

    // 이동 생성자
    Element(Element&& other) noexcept
            : data(std::move(other.data)) {}

    // 복사 생성자 삭제
    Element(const Element& other) = delete;
    Element& operator=(const Element& other) = delete;

    // 이동 대입 연산자
    Element& operator=(Element&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }
};

template <typename T>
class DataBase {
    std::vector<Element<T>> DB;
    mutable std::mutex dbMutex; // DB 접근을 위한 mutex 추가

public:
    // T 타입 객체를 shared_ptr로 변환해 저장
    void save(const std::shared_ptr<T>& t) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        Element<T> element;
        element.data = t; // shared_ptr를 직접 저장
        DB.push_back(std::move(element)); // 요소 추가
    }

    // 특정 ID를 가진 요소를 찾는 함수
    std::shared_ptr<T> find(long id) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        auto it = std::find_if(DB.begin(), DB.end(), [id](Element<T>& elem) {
            std::lock_guard<std::mutex> lock(elem.mtx);  // 요소의 mutex를 잠금
            return elem.data->getId() == id;
        });

        if (it != DB.end()) {
            // 객체의 복사본을 생성하여 반환
            return std::make_shared<T>(*(it->data)); // 복사본 생성
        }
        return nullptr; // 찾지 못하면 nullptr 반환
    }

    void update(std::shared_ptr<T> t) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        auto it = std::find_if(DB.begin(), DB.end(), [t](Element<T>& elem) {
            std::lock_guard<std::mutex> lock(elem.mtx); // 요소의 mutex 잠금
            return elem.data->getId() == t->getId();
        });

        if (it != DB.end()) {
            std::lock_guard<std::mutex> lock(it->mtx); // 업데이트를 위한 잠금
            *(it->data) = *t;  // 데이터 업데이트
        }
    }

    void remove(long id) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        DB.erase(std::remove_if(DB.begin(), DB.end(),
                                [id](Element<T>& elem) {
                                    std::lock_guard<std::mutex> lock(elem.mtx);  // 요소 잠금
                                    return elem.data->getId() == id; // ID 비교
                                }), DB.end());
    }

    long currentIdx() {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        return DB.size();
    }

    void show() {
        std::lock_guard<std::mutex> lock(dbMutex); // DB 접근 잠금
        for (const auto& element : DB) {
            std::lock_guard<std::mutex> lock(element.mtx); // 각 요소의 mutex 잠금
            std::cout << element.data->getId() << " "; // ID 출력
        }
        std::cout << std::endl; // 줄 바꿈
    }
};
#endif // BAEMIN_DATABASE_H
