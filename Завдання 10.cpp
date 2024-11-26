#include <iostream>
#include <string>
#include <regex>

using namespace std;

struct Track {
private:
    string trackName;
    string artist;
    string duration; // формат "мм:сс"

public:
    // Конструктор
    Track(string name, string art, string dur) {
        trackName = name;
        artist = art;
        duration = dur;
    }

    // Функція для перевірки формату тривалості
    bool isValidDuration(string dur) {
        regex pattern(R"(^\d{2}:\d{2}$)"); // Регулярний вираз для "мм:сс"
        return regex_match(dur, pattern);
    }

    // Функція для встановлення тривалості
    void setDuration(string dur) {
        if (isValidDuration(dur)) {
            duration = dur;
        } else {
            cout << "Невірний формат тривалості! Використовуйте формат мм:сс." << endl;
        }
    }

    // Функція для отримання тривалості у секундах
    int convertDurationToSeconds() {
        if (!isValidDuration(duration)) {
            cout << "Тривалість у невірному форматі. Неможливо конвертувати." << endl;
            return -1;
        }

        string minutesStr = duration.substr(0, 2); // Витягуємо хвилини
        string secondsStr = duration.substr(3, 2); // Витягуємо секунди

        int minutes = stoi(minutesStr); // Конвертуємо хвилини у число
        int seconds = stoi(secondsStr); // Конвертуємо секунди у число

        return minutes * 60 + seconds; // Загальна кількість секунд
    }

    // Функція для виведення інформації про трек
    void printTrackInfo() {
        cout << "Назва треку: " << trackName << endl;
        cout << "Виконавець: " << artist << endl;
        cout << "Тривалість: " << duration << endl;

        int totalSeconds = convertDurationToSeconds();
        if (totalSeconds != -1) {
            cout << "Тривалість у секундах: " << totalSeconds << " секунд" << endl;
        }
    }
};

int main() {
    // Створюємо трек
    Track myTrack("Yesterday", "The Beatles", "02:30");

    // Виводимо інформацію про трек
    myTrack.printTrackInfo();

    // Пробуємо змінити тривалість
    myTrack.setDuration("03:45");
    myTrack.printTrackInfo();

    // Пробуємо встановити неправильний формат
    myTrack.setDuration("345");
    myTrack.printTrackInfo();

    return 0;
}
