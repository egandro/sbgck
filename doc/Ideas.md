# Ideas

- SBGCK is a platform for smart board games
- SBGCK is designed as system that will be agnostic to the users platform
- Supported platforms will be
  - Desktop system using a USB camera or IP camera
  - Linux, Windows, macoS (We will also support smartphone [IP camera](https://play.google.com/store/apps/details?id=com.pas.webcam) software).
  - Mobile system using the internal camera e.g. using a gooseneck stand
  - Android and iOS
  - Desktop Systems might get a sexy UI using Electron
- The games are made of "game files" (ZIP file containing an actual game)
- The game language used will Typescript powered by nodejs
- SBGCJ supports nodejs debugging (where available). There will be also some print based logger.


## SBGCK game files

- contains Javascript/Typescript file for game logic
- contains printable assets:
  - this can be PNGs, PDFs, ..
  - instruction, manual, ...
  - board
  - player tokens
  - player remote
  - dice board
  - image maps (JSON)
- contains OpenVC assets (images used as templates camera recognition)
- contains MP3 assets (music, voice of the game)
- contains UI assets (optional UI used before game to configure/load game, html, css, ...)
- SBGCK might offer master game files or embedded game files for having common assets (default assets for MP3, dice OpenCV, library code, etc.)

## Ideas on OpenCV

- OpenCV supports the languages C++, Java and Python
- If we want to go with mobile, Python can't be used for writing apps, Java can't be used for iOS.
- The way to go is C++. We have this on Linux, Windows, macOS. It can be used as shared library in a node module. It can be used on iOS and Android.
- Access to OpenCV will be provided by a JSON API we inject into NodeJS.
- We will only provide limited API to features we want support to NodeJS.

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

- We will provide a simple cli in the "sbgkc" node module (Windows, Linux, MacOS).


## Ideas for a fancy UI (Desktop)

- We will use Electron (Windows, Linux, MacOS).
- Angular UI?

## Ideas for mobile app

- We might go with PhoneGap or similar (might be a pain combining that with OpenCV)

## SVGs

https://stackoverflow.com/questions/31367604/convert-svg-image-to-png-with-transparent-background

## Color Calibration

- https://www.pyimagesearch.com/2021/02/15/automatic-color-correction-with-opencv-and-python/
- Implementation in C++ with Histogram: https://www.morethantechnical.com/2010/01/28/recoloring-via-histogram-matching-with-opencv-w-code/
^^^ simple
- same Idea: https://www.pyimagesearch.com/2014/06/30/super-fast-color-transfer-images/

- https://stackoverflow.com/questions/18897730/how-i-make-color-calibration-in-opencv-using-a-colorchecker
- https://blog.francium.tech/using-machine-learning-for-color-calibration-with-a-color-checker-d9f0895eafdb
- https://plantcv.readthedocs.io/en/latest/transform_color_correction_tutorial/
- https://chowdera.com/2020/12/20201211100511430e.html
- https://github.com/riskiest/color_calibration/tree/v4/doc/pdf/English/Algorithm

- https://github.com/adrianzgaljic/ColorCalibration


## Diff images

- https://stackoverflow.com/questions/27035672/cv-extract-differences-between-two-images
- https://docs.opencv.org/2.4/modules/video/doc/motion_analysis_and_object_tracking.html#backgroundsubtractor
- Library: https://github.com/andrewssobral/bgslibrary

# Online t2s

curl 'https://freetts.com/Home/PlayAudio?Language=en-US&Voice=Matthew_Male&TextMessage=Please%20make%20sure%20the%20camera%20is%20working%2C%20please%20check%20the%20zoomlevel%20and%20make%20sure%20it%20can%20see%20the%20playfield.&id=Matthew&type=1' \
  -H 'authority: freetts.com' \
  -H 'sec-ch-ua: "Google Chrome";v="89", "Chromium";v="89", ";Not A Brand";v="99"' \
  -H 'accept: */*' \
  -H 'dnt: 1' \
  -H 'x-requested-with: XMLHttpRequest' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36' \
  -H 'sec-fetch-site: same-origin' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-dest: empty' \
  -H 'referer: https://freetts.com/' \
  -H 'accept-language: de-DE,de;q=0.9,en-US;q=0.8,en;q=0.7' \
  --compressed

## Ideas for Dice Detection

- https://www.pyimagesearch.com/2016/10/03/bubble-sheet-multiple-choice-scanner-and-test-grader-using-omr-python-and-opencv/

- https://www.davidepesce.com/2019/09/06/dice-reader-part-1/
- https://gideonvos.wordpress.com/2018/09/17/dice-detection-using-opencv/
- https://github.com/Kishaan/Dice-Detection

- https://github.com/andli/dicecounter <<<


## Virtual Filesystem

- https://github.com/yevgeniy-logachev/vfspp
