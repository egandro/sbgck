
export enum CameraType {
	Unknown = 'Unknown',
	Default = 'Default',
	Camera0 = 'Camera0',
	Camera1 = 'Camera1',
	IPCamera = 'IPCamera',
	DebugFile = 'DebugFile',
}

export interface CameraConfig {
	name?: string,
	cameraType?: CameraType,
	url?: string,
	fileName?: string,
}
