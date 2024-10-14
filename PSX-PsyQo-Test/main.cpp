#include <stdint.h>

#include "third_party/nugget/common/syscalls/syscalls.h"
#include "third_party/nugget/psyqo/application.hh"
#include "third_party/nugget/psyqo/font.hh"
#include "third_party/nugget/psyqo/gpu.hh"
#include "third_party/nugget/psyqo/scene.hh"


class App : public psyqo::Application {
    void prepare() override;
    void createScene() override;
};

class HelloAppScene : public psyqo::Scene {
    void frame() override;
};

HelloAppScene rootScene;


// I don't know enough to change this lol
void App::prepare() {
    psyqo::GPU::Configuration config;
    config.set(psyqo::GPU::Resolution::W320)
        .set(psyqo::GPU::VideoMode::AUTO)
        .set(psyqo::GPU::ColorMode::C15BITS)
        .set(psyqo::GPU::Interlace::PROGRESSIVE);
    gpu().initialize(config);
}

void App::createScene() {
    pushScene(&rootScene);
}

void HelloAppScene::frame() {
    psyqo::Color c = {{.r = 0, .g = 0, .b = uint8_t(gpu().getFrameCount() % 255)}};
    gpu().clear(c);
}

int main() { 
    App app;   
    return app.run(); 
}
