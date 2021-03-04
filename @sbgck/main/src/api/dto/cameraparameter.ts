
export enum CameraType {
	Unknown = 'Unknown',
	MobileFront = 'MobileFront',
	MobileBack = 'MobileBack',
	MobileCustom = 'MobileCustom',
	USB = 'USB',
	IPCamera = 'IPCamera',
	DebugFile = 'DebugFile',
}

export interface CameraParameter {
	name?: string,
	url?: string,
	fileName?: string,
	cameraType?: CameraType
}
