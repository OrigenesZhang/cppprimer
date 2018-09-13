class X;
class Y;

class X {
    Y *ptr;
};

class Y {
    X *ptr;
};

int main() {
    return 0;
}