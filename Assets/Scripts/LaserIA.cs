using UnityEngine;
using System.Collections;

public class LaserIA : MonoBehaviour {

	public float speed = 10.0f;

	void start(){

	}
	
	// Update is called once per frame
	void Update () {
		renderer.material.color = new Color (184f/255f, 11f/255f, 140f/255f);
		transform.position += transform.forward * speed * Time.deltaTime; 
	}

	void OnTriggerEnter2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Ennemy")) {
			LifeManager lf =  other.gameObject.GetComponent<LifeManager>();
			lf.hit();
		}
		GameObject.Destroy (this.gameObject);
	}
}
