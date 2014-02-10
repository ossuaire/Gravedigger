using UnityEngine;
using System.Collections;

public class PushBack : MonoBehaviour {

	private bool p;
	public int maxFramesPushed = 20;

	private int framesPushed;

	// Use this for initialization
	void Start () {
		
	}

	public void push() {
		p = true;
	}

	public void endPush() {
		p = false;
		framesPushed = 0;
	}

	public bool isPushed() {
		return p;
	}

	public int numberOfFramesPushed() {
		return framesPushed;
	}

	// Update is called once per frame
	void Update () {
		if (p) {
			framesPushed++;
			if (framesPushed > maxFramesPushed){
				endPush ();
			}
		}
	}
}
