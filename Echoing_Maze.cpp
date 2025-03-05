#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]){
    //khoi tao sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "LOI HE THONG !! KHONG THE KHOI TAO !! LOI: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "SDL khoi tao thanh cong" << std::endl;

    //tao cua so (window)

    std::cout << "Dang tao cua so..." << std::endl;
    SDL_Window* window = SDL_CreateWindow("Echoing Maze", SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == nullptr){
        std::cout << "KHONG THE TAO CUA SO!! LOI: " << SDL_GetError();
        SDL_Quit();
        return -1;
    }
    std::cout << "Cua so da tao thanh cong" << std::endl;

    //tao renderer

    std::cout << "Dang tao renderer..." << std::endl;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::cout << "KHONG THE RENDER MAN HINH!! LOI: " << SDL_GetError();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    std::cout << "Tao renderer thanh cong" << std::endl;

    //mau nen cua so

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    std::cout << "Man hinh da ve xong" << std::endl;

    SDL_Delay(3000);

    //don dep tai nguyen
    std::cout << "Dang giai phong tai nguyen..." << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Chuong trinh da ket thuc!" << std::endl;
    return 0;
}