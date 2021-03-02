https://medium.com/@a7ul/beginners-guide-to-writing-nodejs-addons-using-c-and-n-api-node-addon-api-9b3b718a9a7f

https://nodejs.org/api/addons.html

https://www.npmjs.com/package/create-node-addon

realworld: https://github.com/lwille/node-gphoto2/blob/master/binding.gyp

Windows: chocolatey
-> choco install visualstudio2017-workload-nodebuildtools


We need a bg thread for playing audio: https://github.com/PortAudio/portaudio

(in C++)

For now we can go with a simple

https://www.npmjs.com/package/play-sound

(this is blocking because child process is used)