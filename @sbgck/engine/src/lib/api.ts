
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
    oadGame(gameName: string, language: string): boolean; // not used from NodeJS
    //loadGameList(): string[];
}

export interface CoreNativeAPI {
    // dummy, native
    type: string;

    // C++ functions in the engine
    playSample(str: string): void;
    playSampleSync(str: string, isLocalized: boolean): void;
    stopAllAudio(): void;
    calibrateReferenceFrame(): boolean;
    detectColorCalibrationCard(): boolean;
    //queryTokens(param: QueryTokenParam): QueryTokenResult;
    queryTokens(jsonSting: string): string;
}