import { CameraParameter } from './cameraparameter';

export interface GameParameterBasic {
	assetFolder?: string,
	cameraParameter?: CameraParameter,
}

// this can have more custom parameters that are game specific
export declare interface GameParameter extends GameParameterBasic {

}

