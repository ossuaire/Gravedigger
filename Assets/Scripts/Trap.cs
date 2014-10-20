using UnityEngine;
using System.Collections;

public class Trap : MonoBehaviour {


	public GameObject laser;
	private Transform laserSpawnTransfrom;

	// Use this for initialization
	void Start () {
		laserSpawnTransfrom = transform.FindChild ("LaserSpawnPosition");
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter2D(Collider2D other) {
		if (other.gameObject.CompareTag ("GD")) {
			Vector3 direction = laserSpawnTransfrom.localScale.x >= 0 ? Vector2.right : - Vector2.right;
			Quaternion directionQuat = Quaternion.LookRotation (direction);
			GameObject laserShoot = Instantiate (laser, laserSpawnTransfrom.position, directionQuat) as GameObject;
			Destroy (laserShoot, 1);
		}
	}
}
