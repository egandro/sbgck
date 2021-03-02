# Ideas

- SBGCK is a platform for smart board games
- SBGCK is designed as environment agnostic to the technology used
- Supported platforms will be
  - Desktop system using a USB camera or IP camera (Camera Apps are supported, too)
  - Linux, Windows, macoS
  - Mobile system using the internal camera e.g. using a gooseneck stand

  - Desktop Systems might contain a sexy UI using Electron
- The games are made of "game files" (ZIP file containing am actual game)
- The game language used is Typescript by using nodejs
- SBGCJ supports nodejs debugging (where available). There will be also some print based logger.


## SBGCK game files

- contains javascript assets for game logic
- contains printable assets:
  - board
  - player tokens
  - player remote
  - dice board
- contains OpenVC assets (used camera recognition)
- contains mp3 assets (music, voice of the game)
- contains UI assets  (optional UI used before game to configure/load game)
- SBGCK might offer master game files or embedded game files for having common assets (assets for mp3, dice OpenCV, etc.)

## Ideas on OpenCV

- OpenCV supports the languages C++, Java and Python
- If we want to go with mobile, Python can't be used for writing apps, Java can't be used for iOS.
- The way to go is C++. We have this on Linux, Windows, macOS. It can be used as shared library in a node module. It can be used on iOS and Android.
- Access to OpenCV will be provided by a JSON API we inject into NodeJS.
- We will only provide limited access to features we want support to NodeJS.

## Ideas on NodeJS

- We need a way to embed NodeJS to the mobile world.
- There is an opensource project providing this: <https://github.com/janeasystems/nodejs-mobile>
- Issues to address:
   - communication with OpenCV
   - node-mobile or node might offer a way to export C++ functions in the Javascript world
   - We might not be able (or allowed by Apple) to import npm modules with shared libraries. They are unsigned.
- For the desktop (Windows, Linux, macOS) there are two ideas:
  - Use the C++ embedder API (https://nodejs.org/api/embedding.html) -> we will be the "exe" file.
  - Use the C++ addons API (https://nodejs.org/api/addons.html) -> we will be a npm module.
- We will go with the npm module (with C++ part). The module will contain the desktop version of SBGCK abstracted access to OpenCV. We might provide static linked OpenCV versions here (not sure).
- We will need a npm module containing the runtime and sdk. We provide the same npm module (without any C++ part) for desktop and mobile.

## Ideas for a UI

- We will provide "sbgkc" for the node module (CLI for Windows, Linux, MacOS).


## Ideas for a fancy UI (Desktop)

- We will use Electron (Windows, Linux, MacOS).
- Angular UI?

## Ideas for mobile app

- We might go with PhoneGap or similar (might be a pain combining that with OpenCV)

