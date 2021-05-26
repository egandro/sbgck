const SBGCK = require('../build/Release/glue');


SBGCK.init("./", "http://192.168.1.100:8080/video");
SBGCK.loadGame("dev_game.zip", "en");
SBGCK.loadBoard("fooBar.png");
SBGCK.playSample("Win sound.ogg");
SBGCK.playSampleSync("b5871680917bf331af1dc64ce7388e75.mp3", true);
SBGCK.stopAllAudio()
console.log("calibrateReferenceFrame: ", SBGCK.calibrateReferenceFrame());
console.log("detectColorCalibrationCard:", SBGCK.detectColorCalibrationCard());
console.log("queryTokens:", SBGCK.queryTokens( "{}"));

