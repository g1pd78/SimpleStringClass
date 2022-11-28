#include <cstdio>
#include <cstring>
#include <exception>
#include <stdexcept>

struct SimpleString {
    SimpleString(size_t max_size): max_size{max_size},
    length{}{ // конструктор
        if (max_size == 0){
            throw std::runtime_error{"Max size must be > 0"};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    //конструктор копирования класса
    SimpleString(const SimpleString& other)
    :max_size{other.max_size},
    buffer{new char[other.max_size]},
    length{other.length} {
        std::strncpy(buffer, other.buffer, max_size);
    }


    ~SimpleString(){ // деструктор
        delete[] buffer;
    }

    //оператор присваивания копии
    SimpleString& operator=(const SimpleString& other){
        if (this == &other) return *this;
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer, other.buffer, max_size);
        return *this;
    }
    /*
    SimpleString(const SimpleString&) = default;
    SimpleString& operator=(const SimpleString&) = default;

    SimpleString(const SimpleString&) = delete;
    SimpleString& operator=(const SimpleString&) = delete;

    default - компилятор генерирует реализации для конструктора
    копирования по умолчанию
    delete - здесь запрещает копирование
     */

    //конструктор перемещения
    SimpleString (SimpleString&& other) noexcept
    : max_size{other.max_size},
    buffer(other.buffer),
    length(other.length){
        other.length = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }
    
    //оператор присваивания перемещения
    SimpleString& operator=(SimpleString&& other) noexcept{
        if (thid == &other) return *this;
        delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
        return *this;
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const char* x){
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size)return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
private:
    size_t max_size;
    char* buffer;
    size_t length;
};
// RAII - получение ресурса есть инициализация






int main(){

}