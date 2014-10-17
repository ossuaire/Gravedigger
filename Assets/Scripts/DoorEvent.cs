using UnityEngine;
using System.Collections;

public class DoorEvent : MonoBehaviour {

	private bool ableToTrigger = false;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (ableToTrigger && Input.GetKey (KeyCode.DownArrow))
			Application.LoadLevel ("SandboxDriz");
	}

	void OnTriggerEnter2D(Collider2D other) {
		if(other.gameObject.CompareTag("GD"))
			ableToTrigger = true;
	}

	void OnTriggerExit2D(Collider2D other) {
		ableToTrigger = false;
	}
}
