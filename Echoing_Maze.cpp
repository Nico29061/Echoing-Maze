#include <iostream>
#include <SDL2/SDL.h>

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
    return true;
}

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

int main(int argc, char* argv[]){
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
        SDL_Quit;
        return -1;
    }

    SDL_Delay(3000);

    //giai phong tai nguyen
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Chuong trinh da ket thuc" << std::endl;

    return 0;
}