//Магия – Заклинание – Комбинации

#include <iostream>
#include <string>
using namespace std;

class Magic {
protected:
    string power;
    string grade;
    string danger;
    int hp = 100;
public:
    virtual void neutralized(){
        cout << "This spell has been neutralized!";
    }
    virtual void Grade() = 0;
};

class expelliarmus : public Magic {
public:
    expelliarmus() {
        power = "High";
        grade = "Protection and attack";
        danger = "Medium";
        hp = hp - 20;
    }
    void Grade() override {
        cout << "I'm protecting" << endl;
        cout << hp << " hp";
        cout << endl;
    }
    void neutralized() override {
        cout << "The spell was neutralized" << endl;
    }
    ~expelliarmus() {};
};

class avada_kedavra : public Magic {
public:
    avada_kedavra() {
        power = "Very high";
        grade = "Power attack";
        danger = "Very high";
        hp = hp - 99;
    }
    void Grade() override {
        cout << "I'm attacking" << endl;
        cout << hp << " hp";
        cout << endl;
    }
    void neutralized() override {
        cout << "This spell cannot be neutralized" << endl;
    }
    ~avada_kedavra() {};
};

class expecto_patronum : public Magic {
public:
    expecto_patronum() {
        power = "High";
        grade = "Protection";
        danger = "Medium";
        hp = hp - 5;
    }
    void Grade() override {
        cout << "I protect against dementors" << endl;
        cout << hp << " hp";
        cout << endl;
    }
    void neutralized() override {
        cout << "The spell was neutralized" << endl;
    }
    ~expecto_patronum() {};
};


class expelliarmus_and_avada_kedavra : public Magic, public expelliarmus, public avada_kedavra {
public:
    expelliarmus_and_avada_kedavra() {
    }
    void Grade() override {
        cout << "Avada kedavra will win" << endl;
    }
    void neutralized() override {
        cout << "Interaction of two spells" << endl;
    }

};
class expelliarmus_and_expecto_patronum : public expelliarmus, public expecto_patronum {
public:
    expelliarmus_and_expecto_patronum() {

    }
    void Grade() override {
        cout << "Expecto patronum is more complicated than expelliarmus" << endl;
    }
    void neutralized() override {
        cout << "They can't collide" << endl;
    }
};

int main() {
    expelliarmus exp;
    exp.Grade();
    exp.neutralized();

    cout << endl;

    expelliarmus_and_avada_kedavra Garry_and_VolandeMort;
    Garry_and_VolandeMort.Grade();
    Garry_and_VolandeMort.neutralized();
    return 0;
}


