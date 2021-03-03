import { FileManager } from '../filemanager';
import { GameConfig } from './gameconfig';
import { Event } from './event';

const pjson = require('../../package.json');

export class SBGCK {
	private gameConfig: GameConfig | null = null;

	static getVersion(): string {
		return pjson.version;
	}

	public set assetFolder(value: string) {
		FileManager.assetFolder = value;
	}

	configFile(filename: string): boolean {
		let data = FileManager.readAsString(filename);
		if (data == null) {
			return false;
		}

		this.gameConfig = JSON.parse(data);

		if (this.gameConfig != null) {
			data = FileManager.vfsReadAsString(this.gameConfig.mp3JsonFile);
			if (data != null) {
				this.gameConfig.mp3s = JSON.parse(data);
			}
		}

		return true;
	}

	begin(): boolean {
		if (this.gameConfig == null) {
			return false;
		}

		console.log("name", this.gameConfig.name);
		console.log("default board", this.gameConfig.boards[0].name);
		console.log("template file (vfs)", FileManager.vfsResolveFile(this.gameConfig.boards[0].templateFile));
		console.log("map json file (vfs)", FileManager.vfsResolveFile(this.gameConfig.boards[0].mapJsonFile));

		return true;
	}

	assignToken(name: string) : boolean {
		return false;
	}

	removeToken(name: string) : boolean {
		return false;
	}

	detectEvents() : Event[] {
		const result : Event[] = [
			{
				type: "token"
			}
		]
		return result;
	}

	playMp3ById(id: string) : boolean {
		if (this.gameConfig == null || this.gameConfig.mp3s == null) {
			return false;
		}

		for(const mp3 of this.gameConfig.mp3s) {
			if( mp3.id == id) {
				const filename = FileManager.vfsResolveFile(mp3.file);
				if (filename == null) {
					return false;
				}
				console.log("playing mp3 file: ", filename);
				break;
			}
		}

		return false;
	}

}
