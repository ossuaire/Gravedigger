using UnityEngine;
using System.Collections;

public class PushBack : MonoBehaviour {

	private bool p;
	public float maxTimeBeeingPushed = 0.4f;

	private float startingTime;

	// Use this for initialization
	void Start () {
		
	}

	public void push() {
		p = true;
		startingTime = Time.time;
	}

	public void endPush() {
		p = false;
	}

	public bool isPushed() {
		return p;
	}

	// Update is called once per frame
	void Update () {
		if (p && ( Time.time - startingTime > maxTimeBeeingPushed)) {
			endPush ();
		}
	}
}
