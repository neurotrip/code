#include <iostream>
#include <stdexcept>
#include <fcntl.h>  // Для open()
#include <unistd.h> // Для write() и close()
#include <string.h> // Для strerror()

class File {
public:
    // Конструктор открывает файл
    File(const std::string& filename) : fd(-1) {
        fd = open(filename.c_str(), O_WRONLY | O_TRUNC, 0644);
        if (fd == -1) {
            throw std::runtime_error(std::string("Не удалось открыть файл: ") + strerror(errno));
        }
    }

    // Деструктор закрывает файл
    ~File() {
        if (fd != -1) {
            close(fd);
        }
    }

    // Функция для записи данных в файл
    void write(const std::string& data) {
        if (fd == -1) {
            throw std::runtime_error("Файл не открыт для записи!");
        }

        ssize_t bytesWritten = ::write(fd, data.c_str(), data.size());
        if (bytesWritten == -1) {
            throw std::runtime_error(std::string("Ошибка при записи в файл: ") + strerror(errno));
        }
    }

private:
    int fd; // Дескриптор файла
};

int main() {
    try {
        File file("example.txt");
        file.write("Пример использования POSIX в C++.");
    } catch (...) {
        std::cerr << "Поймано исключение: " << std::endl;
    }

    std::cout << "Программа продолжает выполнение." << std::endl;
    return 0;
}

