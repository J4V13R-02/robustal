#include <iostream>
#include <chrono>
#include "robustal.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    const auto startTime = std::chrono::steady_clock::now();
    Board myBoard{};
    auto lastTime = std::chrono::steady_clock::now() - startTime;
    int ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(lastTime).count());
    std::cout << ms << std::endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}