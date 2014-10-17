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
		if (other.gameObject.CompareTag ("GD"))
			Application.LoadLevel ("SandboxDriz");
		else
			Destroy (other.gameObject);
	}
}
