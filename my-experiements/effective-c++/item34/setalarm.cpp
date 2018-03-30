#include<iostream>
#include<chrono>
#include<memory>

using std::cout;
using std::endl;
using namespace std::chrono;
using namespace std::literals;


class Alarm {
    public:
        using Time = std::chrono::steady_clock::time_point;
        enum class Sound {Beep, Siren, Whistle};
        using Duration = std::chrono::steady_clock::duration;

    public:
        Alarm():
            //t_(steady_clock::now()),
            t_(0),
            s_(Sound::Beep),
            d_(30s)
    {}

        Alarm(int&& t, Sound&& s, Duration&& d) :
            t_(t),
            s_(s),
            d_(d)
    {}

        void set(int&& t, Sound&& s, Duration&& d) {
            t_ = t;
            s_ = s;
            d_ = d;
        }
#if 0
        auto set_sound = [_s=_s](Sound&& s) {
            s_=s;
        }

        auto get_sound = [this]()->Sound& {
            return this->s_;
        }
#endif 
        auto get_sound() {
            return s_;
        }
        
        virtual ~Alarm() = default;
        Alarm(const Alarm&) = default;
        Alarm& operator=(const Alarm&) = default;

        Alarm(Alarm&&) = default;
        Alarm& operator=(Alarm&&) = default;

    private:
        //Time  t_;
        int t_ = 0;
        Sound s_;
        Duration d_;
};


int main() {

    std::shared_ptr<Alarm> alarm = std::make_shared<Alarm>();

    return 0;
}

