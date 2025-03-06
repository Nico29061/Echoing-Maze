#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//ham khoi tao SDL
bool initSDL(){
    std::cout << "Dang khoi tao SDL..." << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL khong the khoi tao!! Loi: " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "SDL khoi tao thanh cong!" << std::endl;

    std::cout << "Dang khoi tao SDL Image..." << std::endl;
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0){
        std::cout << "Khong the khoi tao SDL_image! Loi: " << IMG_GetError() << std::endl;
        return false;
    }
    std::cout << "SDL Image khoi tao thanh cong!" << std::endl;

    return true;
}
//ket thuc phan ham khoi tao SDL

//ham tao cua so
SDL_Window* createWindow(){
    std::cout << "Dang tao cua so..." << std::endl;
    SDL_Window* window = SDL_CreateWindow(
        "Echoing Maze",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr){
        std::cout << "Khong the khoi tao cua so! Loi: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "Khoi tao cua so thanh cong!" << std::endl;
    }

    return window;
}
//ket thuc phan ham tao window

//ham render
SDL_Renderer* createRenderer(SDL_Window* window){
    std::cout << "Dang render..." << std::endl;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == nullptr){
        std::cout << "Khong the render!! Loi: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "Da render thanh cong!" << std::endl;
    }
    return renderer;
}
//ket thuc phan ham render

//ham texture
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path){
    std::cout << "Dang tai texture..." << std::endl;
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if (tempSurface == nullptr){
        std::cout << "Khong the tai hinh anh! Loi: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    std::cout << "Dang tai hinh anh..." << std::endl;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (texture == nullptr){
        std::cout << "Khong the tao texture! Loi: " << SDL_GetError() << std::endl;
    } else {
        std::cout << "Tao hinh anh thanh cong!" << std::endl;
    }

    return texture;
}

//ham gameloop, su kien cua game
void handleEvents(bool &running){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            running = false;
        } else if (event.type == SDL_KEYDOWN){
            std::cout << "Phim nhan: " << event.key.keysym.sym << std::endl;
        }
    }
}

void render(SDL_Renderer* renderer, SDL_Texture* texture){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void updateGame() {

}

void gameLoop(SDL_Renderer* renderer, SDL_Texture* texture){
    std::cout << "Game dang chay..." << std::endl;
    bool running = true;
    while (running){
        handleEvents(running);

        updateGame();

        render(renderer, texture);

        SDL_Delay(16);
    }
}
//ket thuc phan ham vong lap


int main(int argc, char* argv[]){
    std::cout << "Khoi dong console" << std::endl;
    //khoi tao sdl
    if (!initSDL()){
        return -1;
    }

    //tao cua so
    SDL_Window* window = createWindow();
    if (window == nullptr){
        SDL_Quit();
        return -1;
    }

    //render
    SDL_Renderer* renderer = createRenderer(window);
    if (renderer == nullptr){
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    //tai texture
    SDL_Texture* texture = loadTexture(renderer, "resources/images/White_Screen.bmp");
    if (texture == nullptr){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    //chay vong lap
    gameLoop(renderer, texture);

    //giai phong tai nguyen
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();

    return 0;
}