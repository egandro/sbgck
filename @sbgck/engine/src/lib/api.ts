
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

export interface CoreNativeAPI {
    // dummy, native
    type: string;
    //init(baseDir: string): boolean; // not used from NodeJS
    //start(gameName: string, language: string): boolean; // not used from NodeJS

    // C++ functions
    playSample(str: string): void;
    playSampleSync(str: string, isLocalized: boolean): void;
    stopAllAudio(): void;
    calibrateReferenceFrame(): boolean;
    detectColorCalibrationCard(): boolean;
    //queryTokens(param: QueryTokenParam): QueryTokenResult;
    queryTokens(jsonSting: string): string;
}