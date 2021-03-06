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

## C++ signal slots

- https://schneegans.github.io/tutorials/2015/09/20/signal-slot
- http://schneegans.github.io/tutorials/2015/09/21/properties

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

## Android OpenCV

- https://philipplies.medium.com/setting-up-latest-opencv-for-android-studio-and-kotlin-2021-edition-259be404b133
- https://amin-ahmadi.com/2019/02/03/how-to-build-opencv-4-x-for-native-android-development/
- https://github.com/VlSomers/native-opencv-android-template
- https://forum.opencv.org/t/not-able-to-build-opencv-4-5-1-for-android/1073/2
- https://github.com/opencv/opencv/issues/15457
- https://lindevs.com/integrate-opencv-4-into-android-via-gradle/


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
- Embedding node in android <https://www.sisik.eu/blog/android/other/embedding-node-into-android-app>


## Ideas for a UI

- We will provide a simple cli in the "sbgkc" node module (Windows, Linux, MacOS).


## Ideas for a fancy UI (Desktop)

- We will use Electron (Windows, Linux, MacOS).
- Angular UI?

## Ideas for mobile app

- We might go with PhoneGap or similar (might be a pain combining that with OpenCV)
- PhoneGap is dead - welcome Cordoba!
- combine Cordoba with Angular: https://medium.com/@EliaPalme/how-to-wrap-an-angular-app-with-apache-cordova-909024a25d7

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
-  https://docs.opencv.org/master/de/df4/group__color__correction.html
- https://github.com/adrianzgaljic/ColorCalibration
- https://www.youtube.com/watch?v=0rYtZtY5ML4 histogram tutorial for OpenCV
- https://www.pantone.com/pantone-color-match-card
- https://arxiv.org/pdf/1810.08639.pdf
- https://en.wikipedia.org/wiki/ColorChecker
- https://en.wikipedia.org/wiki/File:Color_Checker.pdf


- Good Article: https://www.bluetin.io/opencv/opencv-color-detection-filtering-python/

## Node Module
- https://medium.com/@a7ul/beginners-guide-to-writing-nodejs-addons-using-c-and-n-api-node-addon-api-9b3b718a9a7f
- https://nodejs.org/api/addons.html
- https://www.npmjs.com/package/create-node-addon
- realworld: https://github.com/lwille/node-gphoto2/blob/master/binding.gyp



## Cmake

- https://github.com/cmake-js/cmake-js/issues/200 Cmake.js for multiple archs
- // arch for modules:
- https://stackoverflow.com/questions/17739095 changing-processor-architecture-with-node-gyp-configure
// this is complex shit :(
-  (https://nodeaddons.com/cross-platform-addons-with-node-pre-gyp/)
- https://www.docker.com/blog/multi-arch-images/
- https://www.stereolabs.com/docs/docker/building-arm-container-on-x86/


## Diff images

- https://stackoverflow.com/questions/27035672/cv-extract-differences-between-two-images
- https://docs.opencv.org/2.4/modules/video/doc/motion_analysis_and_object_tracking.html#backgroundsubtractor
- Library: https://github.com/andrewssobral/bgslibrary

# Online t2s

evaluate this: https://ttsmp3.com/ (has better handling)

$ sudo apt-get install jq

FILENAME=voice.mp3

MESSAGE="Das ist eine Sprachausgabe."
VOICE="Hans_Male"
VOICE_ID="Hans"
LANGUAGE="de-DE"

MESSAGE="This is my text message"
VOICE="Matthew_Male"
VOICE_ID="Matthew"
LANGUAGE="en-US"

MESSAGE=$(echo -n ${MESSAGE} |jq -sRr '@uri')
JSON=$(curl -s \
  'https://freetts.com/Home/PlayAudio?Language='${LANGUAGE}'&Voice='${VOICE}'&TextMessage='${MESSAGE}'&id='${VOICE_ID}'&type=1'\
  -H 'authority: freetts.com' \
  -H 'x-requested-with: XMLHttpRequest' \
  -H 'referer: https://freetts.com/' \
  --compressed)

curl -s -o ${FILENAME} https://freetts.com/audio/$(echo ${JSON}  | jq -r ' .id')

## Ink (Game Language - alternative to NodeJS)

- https://www.inklestudios.com/ink/web-tutorial/

## Ideas for Dice Detection

- https://www.pyimagesearch.com/2016/10/03/bubble-sheet-multiple-choice-scanner-and-test-grader-using-omr-python-and-opencv/

- https://www.davidepesce.com/2019/09/06/dice-reader-part-1/
- https://gideonvos.wordpress.com/2018/09/17/dice-detection-using-opencv/
- https://github.com/Kishaan/Dice-Detection

- https://github.com/andli/dicecounter <<<

# Diceboard Detection

- https://stackoverflow.com/questions/44127342/detect-card-minarea-quadrilateral-from-contour-opencv/44131530
- https://docs.opencv.org/3.4/d9/db0/tutorial_hough_lines.html

## Enhance the Feature2D detection

- https://www.youtube.com/watch?v=DZtUt4bKtmY
- source code: https://github.com/bnsreenu/python_for_microscopists
- Try example 30 instead of 29
- ORB detector + ideas how to improve feature detection: https://stackoverflow.com/questions/38309335/c-opencv-feature-detection-with-orb

- http://datahacker.rs/feature-matching-methods-comparison-in-opencv/

## Find complex shapes in OpenCV

- Moments: https://www.youtube.com/watch?v=SZxJb4wtaRU
- https://docs.opencv.org/3.4/d0/d49/tutorial_moments.html < moments: center of contour
- https://laptrinhx.com/practical-opencv-3-image-processing-with-python-245001203/
- Also contains a point in polygon test: http://devdoc.net/linux/OpenCV-3.2.0/d3/dc0/group__imgproc__shape.html
- https://stackoverflow.com/questions/40996514/i-would-like-to-detect-a-custom-shape-using-opencv < highlevel view what is todo
- Match Shapes: https://docs.opencv.org/3.4/d3/dc0/group__imgproc__shape.html#gaadc90cb16e2362c9bd6e7363e6e4c317
- ^^^test if two contours are similar
- example: https://www.programmersought.com/article/96954419978/


## Virtual Filesystem

- https://github.com/yevgeniy-logachev/vfspp
- https://github.com/anthony-y/tiny-vfs
- http://www.icculus.org/physfs/ / http://www.icculus.org/physfs/downloads/?C=M;O=D / https://hg.icculus.org/icculus/physfs/
- https://www.randygaul.net/2019/03/20/virtual-file-systems-in-games/

Single File: https://github.com/mattiasgustavsson/libs assetsys <<< THIS one

# portable sound library

- https://sol.gfxile.net/soloud/downloads.html
- https://sol.gfxile.net/soloud/soloud_20200207.pdf
- https://github.com/bkaradzic/genie
- https://github.com/jarikomppa/soloud << cool - has Cmakefile in contrib
- ^^^ sudo apt-get install libsdl2-dev

- http://www.attr-x.net/yse/
- ^^^ sudo apt-get install libportaudio2 portaudio19-dev libsndfile1 libsndfile1-dev libportmidi0 libportmidi-dev librtmidi-dev

- https://github.com/mackron/miniaudio
- Soloud: Android CMake -> https://github.com/jarikomppa/soloud/issues/168

# NPM

- https://medium.com/cameron-nokes/the-30-second-guide-to-publishing-a-typescript-package-to-npm-89d93ff7bccd


# Music and SFX

- https://opengameart.org/art-search-advanced?keys=&field_art_type_tid%5B%5D=13&sort_by=count&sort_order=DESC
- https://freesound.org/
- https://superdevresources.com/free-music-sound-effects-games/

# Normalize Audio

- https://github.com/Moonbase59/loudgain/blob/master/docs/loudgain.1.md#recommendations

# OpenCV Finger counting

- https://www.youtube.com/watch?v=p5Z_GGRCI5s

# App for game instructions

- https://dized.com

# Custom Code Generator in Cmake

- https://crascit.com/2017/04/18/generated-sources-in-cmake-builds/
