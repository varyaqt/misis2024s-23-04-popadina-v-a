#include <iostream>
#include <vector>
#include <string>
class Go {
public:
    std::vector<std::string> data;
    std::string command;
    virtual void Go(double num) noexcept {
        std::cin >> command;
        std::cin >> num;
    }
    double GetNumber() { return num_; }
    double GetX() { return x_; }
    double GetY() { return y_; }
    void Pop();
    bool IsEmpty() noexcept;
    void REV(int num);

private:
    double num_ = 0;
    double x_ = 0;
    double y_ = 0;
    
};
bool Go::IsEmpty() noexcept {
    if (data.size() == 0) return true;
    else return false;
}
void Go::Pop() {
    if (!IsEmpty()) {
        data.pop_back();
    }
}

void Go::REV(int num) {
    for (int i = 0; i < num; ++i) {
        if (!IsEmpty()) {
            data.pop_back();
        }
    }
}
 // y -
class GoW : public Go {
public:
    void Go(double num) {
        data.push_back("w" + static_cast<std::string>(num));
    }
};

//x +
class GoN : public Go {
public:
    void Go(double num) {
        data.push_back("n" + static_cast<std::string>(num));
    }
};

//y+
class GoE : public Go {
public:
    void Go(double num) {
        data.push_back("e" + static_cast<std::string>(num));
    }
};

//x -
class GoS : public Go {
public:
    void Go(double num) {
        data.push_back("s" + static_cast<std::string>(num));
    }
};

class GoR {
public:
    double GetXStart() { return x_start; }
private:
    double x_start = 0;

};

int main() {
    std::string input;
    std::string function;
    std::
    while (input != "STOP") {
        std::cin>>function>>
    }
	return 0;
}
