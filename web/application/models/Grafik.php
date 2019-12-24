<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Grafik extends CI_model
{
    public function get()
    {

        // $this->db->select('kelembapan');
        // $result = $this->db->get('data_sensor');
        // return $result;

        $this->db->select('*');
        return $this->db->get('data_sensor');
    }
}
