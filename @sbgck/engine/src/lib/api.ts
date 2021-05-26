
export interface QueryTokenParam {
    ROI?: string[],
    timeout?: number,
    names: string[]
}

export interface Token {
    ROI?: string;
    name: string;
}

export interface QueryTokenResult {
    error: string;
    tokens?: Token[];
}

export interface ManagementNativeAPI {
    // C++ functions used for the UI

    init(baseDir: string, cameraUrl: string): boolean; // not used from NodeJS
    loadGame(gameName: string, language: string): boolean; // not used from NodeJS
    //loadGameList(): string[];
}

export interface CoreNativeAPI {
    // dummy, native
    type: string;

    // C++ functions in the engine
    loadBoard(str: string): boolean;
    playSample(str: string): boolean;
    playSampleSync(str: string, isLocalized: boolean): boolean;
    stopAllAudio(): boolean;
    calibrateReferenceFrame(): boolean;
    detectColorCalibrationCard(): boolean;
    //queryTokens(param: QueryTokenParam): QueryTokenResult;
    queryTokens(jsonSting: string): string;
}