#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

class Vehicle {
public:
    double speed;       // km/h
    double distance;    // ön araçla mesafe (m)
    string lane;        // "sol", "orta", "sağ"

    Vehicle() : speed(60), distance(20), lane("orta") {}
};

class SafeSpeed {
private:
    const double speedLimit = 100; // km/h
public:
    void checkLane(Vehicle& car) {
        if (car.lane != "orta") {
            cout << "[Uyarı] Şeritten çıkıyorsunuz!\n";
            car.lane = "orta";
            cout << "[SafeSpeed] Şerit düzeltildi. Şimdi orta şeritte.\n";
        }
    }

    void checkSpeed(Vehicle& car) {
        if (car.speed >= speedLimit - 10 && car.speed < speedLimit) {
            cout << "[Uyarı] Hızı azaltın! Hız sınırına yaklaşıyorsunuz (" << car.speed << " km/h)\n";
        }
        if (car.speed >= speedLimit) {
            cout << "[SafeSpeed] Hız limiti aşıldı! Fren uygulanıyor.\n";
            car.speed = speedLimit;
        }
    }

    void checkDistance(Vehicle& car) {
        if (car.distance < 10) {
            cout << "[Uyarı] Öndeki araca çok yakın! Mesafeyi açın.\n";
            cout << "[SafeSpeed] Hızı düşürerek mesafe açılıyor.\n";
            car.speed -= 10;
            if (car.speed < 0) car.speed = 0;
        }
    }

    void displayLane(const Vehicle& car) {
        cout << "\nŞerit Durumu:\n";
        if (car.lane == "sol") {
            cout << "[A] |     |     \n";
        } else if (car.lane == "orta") {
            cout << "    | [A] |     \n";
        } else if (car.lane == "sağ") {
            cout << "    |     | [A] \n";
        }
    }

    void displaySpeedBar(const Vehicle& car) {
        int barLength = 20;
        string color;

        // Hız sınırına yaklaşırken renk değişiyor
        if (car.speed < 90) color = "\033[32m";      // yeşil
        else if (car.speed < 100) color = "\033[33m"; // sarı
        else color = "\033[31m";                     // kırmızı

        cout << "Hız: " << car.speed << " km/h ";
        cout << "[";
        for (int i = 0; i < barLength; ++i) {
            cout << color << "#" << "\033[0m";
        }
        cout << "]\n";
    }
};

int main() {
    Vehicle car;
    SafeSpeed safespeed;

    cout << "Trafik Hız ve Mesafe Kontrol Simülasyonu (SafeSpeed)\n";
    cout << "Hız sınırı = 100 km/h\n";

    while (true) {
        cout << "\nHız (km/h, -1 çıkış): ";
        cin >> car.speed;
        if (car.speed == -1) break;

        cout << "Şerit (sol/orta/sağ): ";
        cin >> car.lane;

        cout << "Ön araç mesafesi (m): ";
        cin >> car.distance;

        // SafeSpeed kontrolleri
        safespeed.checkLane(car);
        safespeed.checkDistance(car);
        safespeed.checkSpeed(car);

        // Görsellik
        safespeed.displayLane(car);
        safespeed.displaySpeedBar(car);

        cout << "Mesafe: " << car.distance << " m\n";

        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "Simülasyon sonlandı.\n";
    return 0;
}
