#ifndef Counter_cpp
#define Counter_cpp

class InstanceCounter {
    private:
        static int count;

    public:
        InstanceCounter();
        static int getCount();
};

#endif /* Counter_hpp */