using UnityEngine;
using System.Collections;

public class CollisonsHandler : MonoBehaviour {
	

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

	}
	
	void OnCollisionEnter2D(Collision2D other) {
		if (other.gameObject.CompareTag ("Ennemy")) {
			LifeManager lm= other.gameObject.GetComponent<LifeManager>();
			lm.hit ();
		}
		Debug.Log ("trigger");
	}
}
