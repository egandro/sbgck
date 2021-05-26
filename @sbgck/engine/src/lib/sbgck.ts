import { PoTools } from "./tools/potools.class";
import { State } from './statemachine';
import { CoreNativeAPI, QueryTokenParam, QueryTokenResult } from './api';

class APIDummy implements CoreNativeAPI {
    type: string = "dummy";

    private delay(ms: number): void {
        Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, ms);
    }

    setBoard(str: string): boolean {
        console.log(str);
        return true;
    }

    playSample(str: string): boolean {
        console.log(str);
        return true;
    }

    playSampleSync(str: string, isLocalized: boolean): boolean {
        console.log(str);
        return true;
    }

    stopAllAudio(): boolean {
        console.log('   background music stopped');
        return true;
    }

    hack1 = true;
    calibrateReferenceFrame(): boolean {
        if (this.hack1) {
            this.hack1 = false;
            return false;
        }
        return true;
    }

    private calibrationCounter= 0;
    detectColorCalibrationCard(): boolean {
        const arr = [false, true, true, false];
        if(this.calibrationCounter>arr.length) {
            return false;
        }

        const result = arr[this.calibrationCounter];
        this.calibrationCounter++;

        return result;
    }

    hack3 = true;
    queryTokens(jsonSting: string): string {
        const param: QueryTokenParam = JSON.parse(jsonSting);
        const obj: QueryTokenResult = {
            error: ""
        }

        if (param.timeout) {
            this.delay(param.timeout);
        }

        if (this.hack3) {
            this.hack3 = false;
            return JSON.stringify(obj);
        }

        this.hack3 = true;
        obj.tokens = [{
            name: 'Blue Pentagon'
        }];

        return JSON.stringify(obj);
    }
}

export abstract class GameState extends State {
    public static api: CoreNativeAPI = new APIDummy();
    public static verboseText: boolean = true;

    setBoard(str: string): boolean {
        let board = str;

        if (GameState.api.type == "dummy") {
            board = `   set board: ${str}`;
        }

        return GameState.api.setBoard(board);
    }

    text(str: string): boolean {
        const message = PoTools.getMessage(str);

        const mp3 = message.mp3;
        const role = message.role;
        let text = message.message;

        if (role == "") {
            text = "FIX ME: no role in text " + str;
        }

        let sample = mp3;

        if (GameState.api.type == "dummy") {
            if (GameState.verboseText) {
                sample = `   audio [${mp3}] [${role}]: ${text}`;
            } else {
                sample = `   audio: ${str}`;
            }
        }

        return GameState.api.playSampleSync(sample, true);
    }

    randomText(...args: string[]): boolean {
        const i = Math.floor(Math.random() * args.length);
        return this.text(args[i]);
    }

    bgMusic(str: string): boolean {
        let sample = str;

        if (GameState.api.type == "dummy") {
            sample = `   looped background music: ${str}`;
        }

        return GameState.api.playSample(sample);
    }

    sfx(str: string): boolean {
        let sample = str;

        if (GameState.api.type == "dummy") {
            sample = `   sfx: ${str}`;
        }

        return GameState.api.playSample(sample);
    }

    stopAllAudio(): boolean {
        return GameState.api.stopAllAudio();
    }

    delay(ms: number): void {
        Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, ms);
    }

    calibrateReferenceFrame(): boolean {
        return GameState.api.calibrateReferenceFrame();
    }

    detectColorCalibrationCard(): boolean {
        return GameState.api.detectColorCalibrationCard();
    }

    queryTokens(param: QueryTokenParam): QueryTokenResult {
        const json = JSON.stringify(param);
        // C++ api has json string param/result
        const strResult = GameState.api.queryTokens(json);
        const result: QueryTokenResult = JSON.parse(strResult);
        return result;
    }
}