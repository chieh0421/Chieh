using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MagicBox : MonoBehaviour {
    public Bean beanPrefab;
    bool isUsed;
    void Start()
    {
        isUsed = false;
    }

    void OnCollisionEnter(Collision collision)
    {
        GameObject other = collision.gameObject;
        if(!isUsed && other.name == "Player")
        {
            isUsed = true;
            Debug.Log("Collison");
            Bean bean = Instantiate(beanPrefab);
            Vector3 diff = transform.position - other.transform.position;
            Vector3 pos = transform.position + diff;
            bean.transform.position = pos;
        }
    }
}
