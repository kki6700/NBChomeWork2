#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal {
public:
    virtual void makeSound() { cout << "미야옹" << endl; }  
    virtual void move() { cout << "동물이 움직입니다." << endl; }
    virtual ~Animal() {}  
};

class Cat : public Animal {
public:
    void makeSound() override { cout << "미야옹" << endl; }
    void move() override { cout << "고양이가 살금살금 걸어요" << endl; }
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "멍멍~~!" << endl; }
    void move() override { cout << "강아지가 신나게 뜁니다" << endl; }
};

class Cow : public Animal {
public:
    void makeSound() override { cout << "음머어" << endl; }
    void move() override { cout << "소가 천천히 걸어요" << endl; }
};

class Zoo {
private:
    Animal* animals[10];
    int count = 0;

public:
    void addAnimal(Animal* animal) {
        if (count < 10) {
            animals[count++] = animal;
        }
        else {
            cout << "더 이상 동물을 추가할 수 없습니다." << endl;
        }
    }

    void performActions() {
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound();
            animals[i]->move();  
        }
    }

    ~Zoo() {
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int r = rand() % 3;
    if (r == 0) return new Dog();
    else if (r == 1) return new Cat();
    else return new Cow();
}

int main() {
    srand((unsigned int)time(0));
    Zoo zoo;

    for (int i = 0; i < 5; ++i) {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();
    return 0;
}
