#include <iostream>
#include <chrono>
#include <thread>

class TrafficLight {
public:
    TrafficLight(int red_duration, int green_duration, int yellow_duration)
        : red_time(red_duration), green_time(green_duration), yellow_time(yellow_duration) {}

    void start() {
        while (true) {
            changeState("Red", red_time);
            changeState("Green", green_time);
            changeState("Yellow", yellow_time);
        }
    }

private:
    int red_time, green_time, yellow_time;

    void changeState(const std::string& color, int duration) {
        std::cout << color << " light - ";
        if (color == "Red")
            std::cout << "STOP!";
        else if (color == "Green")
            std::cout << "GO!";
        else if (color == "Yellow")
            std::cout << "SLOW DOWN!";
        
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }
};

int main() {
    TrafficLight trafficLight(5, 5, 2);
    trafficLight.start();
    return 0;
}
