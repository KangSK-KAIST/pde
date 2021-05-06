#include <SDL2/SDL.h>

#include <iostream>

#include "config.hpp"

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gXOut = nullptr;

bool init() {
  // Initialization flag
  bool success = true;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    success = false;
  } else {
    // Create window
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
      std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
                << std::endl;
      success = false;
    } else {
      // Get window surface
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
  return success;
}

void close() {
  // Deallocate surface
  SDL_FreeSurface(gXOut);
  gXOut = nullptr;
  // Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  // Quit SDL subsystems
  SDL_Quit();
}

int main(int argc, char* args[]) {
  // Start up SDL and create window
  if (!init()) {
    std::cerr << "Failed to initialize!" << std::endl;
  } else {
    // Main loop flag
    bool quit = false;
    // Event handler
    SDL_Event e;
    // While application is running
    while (!quit) {
      // Handle events on queue
      while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
          quit = true;
        } else if (e.type == SDL_KEYDOWN) {
          std::cerr << "No key input possible." << std::endl;
        }
      }
      // Apply the image
      SDL_BlitSurface(gXOut, nullptr, gScreenSurface, nullptr);
      // Update the surface
      SDL_UpdateWindowSurface(gWindow);
    }
  }
  // Free resources and close SDL
  close();
  return 0;
}