// #pragma once

// #include <SDL2/SDL.h>
// #include <chrono>
// #define sleepMS(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms))

// class Game {
//  public:
// 	Game() = default;
// 	~Game() = default;
// 	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
// 		if (isRunning) this->clean();
// 		WindowHeight = height;
// 		WindowWidth = width;
// 		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
// 			std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
// 			isRunning = false;
// 			return;
// 		}

// 		int flags;
// 		fullscreen ? flags = SDL_WINDOW_FULLSCREEN : flags = 0;
// 		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
// 		if (!window) {
// 			isRunning = false;
// 			return;
// 		}
// 		std::cout << "Window created!" << std::endl;

// 		renderer = SDL_CreateRenderer(window, -1, 0);
// 		if (!renderer) {
// 			isRunning = false;
// 			return;
// 		}
// 		std::cout << "Renderer created!" << std::endl;
// 		isRunning = true;
// 	}
// 	void handleEvents() {
// 		SDL_Event event;
// 		SDL_PollEvent(&event);
// 		const Uint8 *state = SDL_GetKeyboardState(NULL);
// 		if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE]) isRunning = false;
// 	}
// 	//void update() {}
// 	void render() {
// 		SDL_RendererFlip check = SDL_FLIP_NONE;
// 		SDL_RenderCopy(renderer, VignetteTexture, nullptr, nullptr);
// 		SDL_RenderPresent(renderer);
// 	}
// 	void clean() {
// 		std::cout << SDL_GetError();
// 		SDL_DestroyWindow(window);
// 		SDL_DestroyRenderer(renderer);
// 		SDL_Quit();
// 		std::cout << "Game cleaned!" << std::endl;
// 	}
// 	bool running() { return isRunning; }
// 	void setRunning(bool r) { isRunning = r; }
// 	uint8_t frameDelay = 1000 / 60; // 60 fps
// 	uint32_t frameStart = 0;
// 	uint32_t frameTime = 0;

//  private:
// 	int WindowWidth = 0;
// 	int WindowHeight = 0;
// 	bool isRunning = false;
// 	SDL_Window *window = nullptr;
// 	SDL_Renderer *renderer = nullptr;
// 	SDL_Texture *VignetteTexture = nullptr;
// 	double numEnemiesNormDist(uint8_t time) {
// 		constexpr double mu = 0.5;
// 		constexpr double sigma = 0.1;
// 		return exp(-pow(time - mu, 2) / (2 * pow(sigma, 2))) /
// 			   sqrt(6.28318531 * pow(sigma, 2));
// 	}
// 	double numEnemiesExp(uint8_t time) {
// 		constexpr double scale = 1;
// 		constexpr double exp = 1;
// 		return scale * pow(time, exp);
// 	}
// };
