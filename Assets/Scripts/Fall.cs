using UnityEngine;
using System.Collections;

public class Fall : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}


	void OnTriggerEnter2D(Collider2D other) {
		Debug.Log ("Dans le vide là !!");
		Application.LoadLevel ("SandboxDriz");
	}
}
