# android-botlib

**android-botlib** is a library designed to simplify Android automation by combining the power of `scrcpy`, `adb`, and `OpenCV` with the scripting flexibility of Lua.
This allows you to easily create scripts for automating various tasks on Android devices.

For now android-botlib **only supports Linux**, since the screen content is captured and processed with Linux's V4L API.

## Features
*   **OpenCV:** Uses OpenCV pattern matching and pixel color testing enabling automation based on screen content.
*   **Device Control:** Uses `adb` for device interaction (clicks and swipes).
*   **Lua Scripting:** Employs Lua as the scripting language, making it easy to write scripts.

