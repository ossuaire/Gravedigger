using UnityEngine;
using System.Collections;

public class MoveRightLeft : MonoBehaviour {

	public float timeRevertDir = 2.0f;
	public float deltaX = 2.0f;
	
	private int direction = 1;
	private float changeDirTime=2.0f;
	
	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		changeDirTime -= Time.deltaTime;
		if (changeDirTime < 0) {
			direction = -direction;
			changeDirTime = timeRevertDir;
			transform.localScale = new Vector3(direction,1,1);
		}
		transform.Translate ( direction * deltaX * Time.deltaTime ,0, 0);
	}
}
