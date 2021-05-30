// const SBGCK = require('../build/Release/glue');
const SBGCK = require('../build/Debug/glue');

// console.log('Press any key to continue.');
// process.stdin.once('data', function () {

SBGCK.init(__dirname + "/..", "http://192.168.1.100:8080/video", true);
if (!SBGCK.loadGame("dev_game", "en")) {
    process.exit(1);
}
console.log("setBoard", SBGCK.setBoard("Arctic"));
// // Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, 5000);
// // console.log("xxxxxxxxxxxx");
// SBGCK.playSampleSync("Win sound.ogg", false);
SBGCK.playSample("Win sound.ogg");
// SBGCK.playSample("lose sound 1_0.ogg");
// // Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, 5000);
// // console.log("yyyyyyyyyyyy");

// SBGCK.playSample("Ove - Earth Is All We Have .ogg");
// Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, 2000);
// SBGCK.playSampleSync("b5871680917bf331af1dc64ce7388e75.mp3", true);
// Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, 10000);
// SBGCK.stopAllAudio();
// console.log("All Audio stopped");
console.log("calibrateReferenceFrame: ", SBGCK.calibrateReferenceFrame());
console.log("detectColorCalibrationCard:", SBGCK.detectColorCalibrationCard());

console.log('Press any key to continue.');
process.stdin.once('data', function () {

    const cfg = {
        ROI: [],
        timeout: 200,
        //names: ["Blue Triangle", "Red Circle", "Green Hexagon"],
        names: ["Green Hexagon"],
        // showColorDiff: true,
        // showAllROIs: true,
        // showContours: true
    };

    const jsonStr = JSON.stringify(cfg);
    console.log("queryTokens:", SBGCK.queryTokens(jsonStr));

    console.log("bye.");
    process.exit(0);
});
