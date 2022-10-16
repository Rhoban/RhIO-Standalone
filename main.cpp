#include <chrono>
#include <thread>
#include <RhIO.hpp>

using namespace std::chrono_literals;

int main()
{
  RhIO::start();
  RhIO::Bind bind("main");

  double amplitude = 1.0;
  double frequency = 1.0;
  double pos_x = 0.;
  double pos_y = 0.;

  bind.bindNew("amplitude", amplitude, RhIO::Bind::PullOnly)
    ->comment("Oscillation amplitude")
    ->defaultValue(amplitude);
  bind.bindNew("frequency", frequency, RhIO::Bind::PullOnly)
    ->comment("Oscillation frequency")
    ->defaultValue(frequency);

  bind.bindNew("posX", pos_x, RhIO::Bind::PushOnly);
  bind.bindNew("posY", pos_y, RhIO::Bind::PushOnly);

  double dt = 0.01;
  double t = 0.0;

  while (true) {
    bind.pull();

    t += dt * frequency;
    pos_x = cos(t) * amplitude;
    pos_y = sin(t) * amplitude;

    bind.push();

    std::this_thread::sleep_for(10ms);
  }
}