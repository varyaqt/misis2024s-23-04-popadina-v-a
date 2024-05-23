#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Go {
public:
    virtual void Go(double num) noexcept {
        SetCmds.push_back(num);
    }
    std::vector<double> SaveCmds;
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
    std::vector<std::unique_ptr <SaveCmds>> cmd;    
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
    void Go(double num) override {
        
    }
};

//x +
class GoN : public Go {
public:
    void Go(double num) override {
        
    }
};

//y+
class GoE : public Go {
public:
    void Go(double num) override {
        
    }
};

//x -
class GoS : public Go {
public:
    void Go(double num) override {
        
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
