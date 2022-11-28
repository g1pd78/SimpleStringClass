#include <cstdio>
#include <cstring>
#include <exception>

struct SimpleString {
    SimpleString(size_t max_size): max_size{max_size},
    length{}{
        if (max_size == 0){
            throw std::runtime_error{"Max size must be > 0"};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(const SimpleString& other): max_size{other.max_size},
    buffer{new char[other.max_size]},
    length{other.length} {
        std::strcpy(buffer, other.buffer, max_size);
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const chat* x){
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size)return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
}
// RAII - получение ресурса есть инициализация
~SimpleString(){
    delete[] buffer;
}


SimpleString& operator=(SimpleString&& other) noexcept{
    if (this == &other) return *this;
    delete[] buffer;
    buffer = other.buffer;
    length = other.length;
    max_size = other.max_size;
    other.buffer = nullptr;
    other.length = 0;
    other.max_size = 0;
    return *thisl
 }

int main(){

}