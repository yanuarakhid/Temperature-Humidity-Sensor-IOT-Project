<?php
defined('BASEPATH') or exit('No direct script access allowed');


class save extends CI_Controller
{
    public function index()
    {
        $this->load->model('send');

        if (isset($_GET['s']) && ($_GET['k'])) {
            $s = $this->input->get('s');
            $k = $this->input->get('k');
            $data['suhu'] = $s;
            $data['kelembapan'] = $k;
            $data['waktu'] = time();
            $data['title'] = "Input Data Sensor";


            $fromsensor = array(
                'suhu' => $s,
                'kelembapan' => $k,
                'waktu' => time()
            );


            $this->load->view('templates/head', $data);
            $this->load->view('save/index', $data);
            $this->load->view('templates/footer');

            $this->send->save($fromsensor);
        } else {
            echo 'hayoo rakenek';
        }
    }
}
