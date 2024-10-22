#ifndef BAEMIN_DATABASE_H
#define BAEMIN_DATABASE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>

// ������ ��ҿ� �� ����� mutex�� �Բ� ���� ����ü
template <typename T>
class Element {
public:
    std::shared_ptr<T> data;
    mutable std::mutex mtx;  // �� ��Ҹ��� �������� mutex

    // �⺻ ������
    Element() = default;

    // �̵� ������
    Element(Element&& other) noexcept
            : data(std::move(other.data)) {}

    // ���� ������ ����
    Element(const Element& other) = delete;
    Element& operator=(const Element& other) = delete;

    // �̵� ���� ������
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
    mutable std::mutex dbMutex; // DB ������ ���� mutex �߰�

public:
    // T Ÿ�� ��ü�� shared_ptr�� ��ȯ�� ����
    void save(const std::shared_ptr<T>& t) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        Element<T> element;
        element.data = t; // shared_ptr�� ���� ����
        DB.push_back(std::move(element)); // ��� �߰�
    }

    // Ư�� ID�� ���� ��Ҹ� ã�� �Լ�
    // ã�� ���ϸ� nullptr ��ȯ
    std::shared_ptr<T> find(long id) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        auto it = std::find_if(DB.begin(), DB.end(), [id](Element<T>& elem) {
            std::lock_guard<std::mutex> lock(elem.mtx);  // ����� mutex�� ���
            return elem.data->getId() == id;
        });

        if (it != DB.end()) {
            // ã�� ��ü�� �����͸� ��ȯ
            return it->data; // ��ü�� �����͸� ��ȯ
        }
        return nullptr; // ã�� ���ϸ� nullptr ��ȯ
    }

    // ������ ������Ʈ
    void update(std::shared_ptr<T> t) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        auto it = std::find_if(DB.begin(), DB.end(), [t](Element<T>& elem) {
            std::lock_guard<std::mutex> lock(elem.mtx); // ����� mutex ���
            return elem.data->getId() == t->getId();
        });

        if (it != DB.end()) {
            std::lock_guard<std::mutex> lock(it->mtx); // ������Ʈ�� ���� ���
            *(it->data) = *t;  // ������ ������Ʈ
        }
    }

    // ���� ��û�� ��ü�� vector �ȿ� ���ٸ� �ƹ� �ൿ�� ���� ����
    void remove(long id) {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        DB.erase(std::remove_if(DB.begin(), DB.end(),
                                [id](Element<T>& elem) {
                                    std::lock_guard<std::mutex> lock(elem.mtx);  // ��� ���
                                    return elem.data->getId() == id; // ID ��
                                }), DB.end());
    }

    long currentIdx() {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        return DB.size();
    }

    void show() {
        std::lock_guard<std::mutex> lock(dbMutex); // DB ���� ���
        for (const auto& element : DB) {
            std::lock_guard<std::mutex> lock(element.mtx); // �� ����� mutex ���
            std::cout << element.data->getId() << " "; // ID ���
        }
        std::cout << std::endl; // �� �ٲ�
    }
};
#endif // BAEMIN_DATABASE_H
