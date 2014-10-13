using UnityEngine;
using System.Collections;

public class FloorGenerator : MonoBehaviour {
	

	void Start () {

		//float w = 0.1f*this.transform.localScale.x/2f;
		//float h = 0.1f*this.transform.localScale.y/2f;
		// #1 for each column
		/*for (int i = 0; i<wallLayout.layout.Length; ++i) {
			// #2 foreach row
			for (int j = 0; j<wallLayout.layout[i].Length; ++j){
				// #2a get the type of the box
				char type = this.wallLayout.layout[i][j];
				GameObject brick = Wall.getBrick(type);
				if (brick!=null){
					brick.transform.parent = this.transform;
					// #2b process the scale, aims to be 10 for now
					brick.transform.localScale = new Vector3(10.0f/this.transform.localScale.x, 
					                                         10.0f/this.transform.localScale.y,0f);
					// #2b process the new position
					float x = this.transform.position.x + w - (0.1f*15*i) - 0.5f;
					float y = this.transform.position.y + h - (0.1f*15*j) - 1f;
					// #2c instanciante a new gameObject
					brick.transform.position = new Vector3(x, y, 0);
				};
			};
		};*/
	}

}
