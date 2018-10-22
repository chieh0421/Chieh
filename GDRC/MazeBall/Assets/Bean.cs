using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bean : MonoBehaviour
{

    // Use this for initialization

    void OnTriggerEnter(Collider collider)
    {
        if (collider.name == "Player")
        {
            Destroy(gameObject);
            collider.GetComponent<Player>().addScore();
        }
    }

}

