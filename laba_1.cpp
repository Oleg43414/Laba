#include <iostream>
#include <string>
#include <cmath>
#include <limits>

double perimeter(double footing, double wall_left, double wall_right) {
    return (footing + wall_left + wall_right);
}

double square(double footing, double wall_left, double wall_right) {
    double s = (footing + wall_left + wall_right) / 2;
    return std::sqrt(s * (s - footing) * (s - wall_left) * (s - wall_right));
}

bool isIsosceles(double footing, double wall_left, double wall_right) {
    return (footing == wall_left || footing == wall_right || wall_left == wall_right);
}

double inputSide(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cout << "Некорректный ввод! Введите положительное число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    double footing = inputSide("Введите основание треугольника: ");
    double wall_left = inputSide("Введите левую сторону треугольника: ");
    double wall_right = inputSide("Введите правую сторону треугольника: ");

    if (footing >= (wall_left + wall_right) || wall_left >= (footing + wall_right) || wall_right >= (footing + wall_left)) {
        std::cout << "Такого треугольника не существует!!!" << std::endl;
        return 0;
    }
    std::cout << "Периметр = " << perimeter(footing, wall_left, wall_right) << std::endl;
    std::cout << "Площадь = " << square(footing, wall_left, wall_right) << std::endl;

    if (isIsosceles(footing, wall_left, wall_right)) {
        std::cout << "Треугольник равнобедренный" << std::endl;
    }
    return 0;
}

