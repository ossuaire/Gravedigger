using UnityEngine;
using System.Collections;

public class LaserIA : MonoBehaviour {

	public float speed = 10.0f;
	public bool killGD;
	public Color laserColor = new Color (184f/255f, 11f/255f, 140f/255f);

	void Update () {
		renderer.material.color = laserColor;
		transform.position += transform.forward * speed * Time.deltaTime;
	}

	void OnTriggerEnter2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Ennemy")) {
			LifeManager lf = other.gameObject.GetComponent<LifeManager> ();
			lf.hit ();

			PushBack pb = other.gameObject.GetComponent<PushBack> ();
			pb.push ();
		} else {
			if (killGD && other.gameObject.CompareTag ("GD")) {
				Application.LoadLevel (Application.loadedLevelName);
			}
		}
		GameObject.Destroy (this.gameObject);
	}
	
}
