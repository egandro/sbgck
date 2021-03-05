import { AudioImplementation } from '@sbgck/desktop';

import { CameraConfig } from './dto/cameraconfig';
import { FileManager } from '../filemanager';
import { GameConfig } from './dto/config/gameconfig';
import { Material } from './dto/material';
import { Event } from './dto/event';

const pjson = require('../../package.json');

export class SBGCK {
	private fileManager: FileManager = new FileManager();
	private gameConfig: GameConfig | null = null;
	private audio: AudioImplementation | null = null;

	static cameraConfig: CameraConfig;
	static assetFolder: string;

	static getVersion(): string {
		return pjson.version;
	}

	constructor(gameConfigFilename: string) {
		this.audio = new AudioImplementation();

		this.fileManager.assetFolder = SBGCK.assetFolder;

		if (!this.parseConfigFile(gameConfigFilename) || this.gameConfig == null) {
			throw new Error("can't parse gameconfig file.");
		}
	}

	assignMaterial(assetName: string): Material | null {
		return null;
	}

	removeMaterial(assetName: string): Material | null {
		return null;
	}

	detectEvents(): Event[] {
		const result: Event[] = [
			{
				type: "token"
			}
		]
		return result;
	}

	playMp3ById(id: string): boolean {
		if (this.gameConfig == null || this.gameConfig.mp3s == null) {
			return false;
		}

		for (const mp3 of this.gameConfig.mp3s) {
			if (mp3.id == id) {
				const filename = this.fileManager.vfsResolveFile(mp3.file);
				if (filename == null) {
					return false;
				}
				console.log("playing mp3 file:", filename);
				if (this.audio != null) {
					this.audio.playMp3(filename);
				}
				break;
			}
		}

		return false;
	}

	begin(): boolean {
		if (this.gameConfig == null) {
			throw new Error("no game config");
		}

		console.log("game name:", this.gameConfig.name);
		console.log("default board:", this.gameConfig.boards[0].name);
		console.log("default board template file (vfs):", this.fileManager.vfsResolveFile(this.gameConfig.boards[0].templateFile));
		console.log("default board map json file (vfs):", this.fileManager.vfsResolveFile(this.gameConfig.boards[0].mapJsonFile));

		if (SBGCK.cameraParameter == null) {
			throw new Error("no camera parameters");
		}

		console.log("camera name:", SBGCK.cameraParameter.name);
		console.log("camera cameraType:", SBGCK.cameraParameter.cameraType);
		if (SBGCK.cameraParameter.url) {
			console.log("camera url:", SBGCK.cameraParameter.url);
		}
		if (SBGCK.cameraParameter.fileName) {
			console.log("camera fileName:", SBGCK.cameraParameter.fileName);
		}

		return true;
	}

	end(): boolean {
		if (this.gameConfig == null) {
			return false;
		}

		return true;
	}

	private parseConfigFile(filename: string): boolean {
		let data = this.fileManager.readAsString(filename);
		if (data == null) {
			return false;
		}

		this.gameConfig = JSON.parse(data);

		if (this.gameConfig != null) {
			data = this.fileManager.vfsReadAsString(this.gameConfig.mp3JsonFile);
			if (data != null) {
				this.gameConfig.mp3s = JSON.parse(data);
			}
		}

		return true;
	}
}
