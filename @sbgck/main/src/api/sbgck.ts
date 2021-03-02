const pjson = require('../../package.json');

export class SBGCK {
	static getVersion() : string {
		return pjson.version;
	}

	static getFoo() : string {
		return "foo";
	}
}
